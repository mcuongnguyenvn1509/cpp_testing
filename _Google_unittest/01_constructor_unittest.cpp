#include "01_constructor.h"
#include "gtest/gtest.h"

namespace {
        TEST(MyConstructor, DefaultConstructor){ //test for constructor 1
                Constructor c;
                EXPECT_STREQ(nullptr, c.getString());
        }

	TEST(MyConstructor, Constructor2){
		Constructor c2(3,18);
		EXPECT_EQ(c2.getId(),3);
		EXPECT_EQ(c2.getLength(), 18);
		//EXPECT_STREQ(c2.getString(),nullptr);

	}
	TEST(MyConstructor, Constructor4){
		Constructor c4("String4", 16);
		EXPECT_EQ(0,c4.getId());
		EXPECT_STREQ("String4",c4.getString());
		EXPECT_EQ(16, c4.getLength());
	}
	TEST(MyConstructor, CopyConstructorTC1){ //Test for copy constructor with constructor 2
		Constructor cc2(3, 18);
		Constructor cc3(cc2);
		EXPECT_STREQ(cc2.getString(),cc3.getString());
		EXPECT_EQ(cc2.getId(),cc3.getId());
		EXPECT_EQ(cc2.getLength(),cc3.getLength());

	}
	TEST(MyConstructor, CopyConstructorTC2){ //Test for copy constructor with constructor 3
	        Constructor cc2("String2", 16);
        	Constructor cc3(cc2);
	        EXPECT_STREQ(cc2.getString(),cc3.getString());
        	EXPECT_EQ(cc2.getId(),cc3.getId());
	        EXPECT_EQ(cc2.getLength(),cc3.getLength());

	}	
	TEST(MyConstructor, Assignment_OperatorTC1){ //Test for Assignment operator  with constructor 2
		Constructor cc2(3, 18);
		Constructor cc3(3, 15);
		cc3 = cc2;
		EXPECT_STREQ(cc2.getString(),cc3.getString());
		EXPECT_EQ(cc2.getId(),cc3.getId());
		EXPECT_EQ(cc2.getLength(),cc3.getLength());

	}
	TEST(MyConstructor, Assignment_OperatorTC2){ //Test for Assignment operator  with constructor 3
        	Constructor cc2("String2", 18);
        	Constructor cc3(3, 15);
        	//Constructor cc3;
        	cc3 = cc2;
        	EXPECT_STREQ(cc2.getString(),cc3.getString());
        	EXPECT_EQ(cc2.getId(),cc3.getId());
        	EXPECT_EQ(cc2.getLength(),cc3.getLength());

	}	

}
