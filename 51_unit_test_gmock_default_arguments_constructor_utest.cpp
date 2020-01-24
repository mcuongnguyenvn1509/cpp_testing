#include "gmock/gmock.h"
class MockAverage : public Average{
        public:
                MOCK_METHOD(void, compute, (), (override));

}
