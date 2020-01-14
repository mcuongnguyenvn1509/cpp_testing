#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;


class DataBaseConnect {
public:
	virtual bool login(string username, string password)
	{
		return true;
	}
	virtual bool logout(string username) {return true;}
	virtual int fetchRecord(){return -1;}

};

class MockDB : public DataBaseConnect {
public:
	MOCK_METHOD0(fetchRecord, int());
	MOCK_METHOD1(logout, bool(string username));
	MOCK_METHOD2(login, bool(string username, string password));

};
class MyDatabase{
	DataBaseConnect & dbC;
public:
	MyDatabase (DataBaseConnect & _dbC) : dbC(_dbC){}
	int Init(string username, string password){
		if(dbC.login(username, password) != true){
			cout<<"DB FAILURE" << endl; return -1;
		} else {
			cout<<"DB SUCCESS" << endl; return 1;
		}
	}
};

TEST(MyDBTest, LoginTest){
	MockDB mdb;
	MyDatabase db(mdb);
	EXPECT_CALL(mdb, login("Terminator", "I'm back"))
	.Times(1)
	.WillOnce(Return(true));
	int retValue = db.Init("Terminator", "I'm back");
	EXPECT_EQ(retValue, 1);
}
int main(int argc, char **argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

