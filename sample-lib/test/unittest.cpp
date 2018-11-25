//
// Created by timoptr on 25/11/2018.
//

using namespace std;

class LibTestFixture : public ::testing::Test {
public:
    LibTestFixture() {
        // initialization code here
    }

    void SetUp() {
        // code here will execute just before the test ensues
    }

    void TearDown() {
        // code here will be called just after the test completes
        // ok to through exceptions from here if need be
    }

protected:
    // put in any custom data members that you need
};

TEST_F(LibTestFixture, TEST-NAME) {
    // Your test
    ASSERT_EQ(output.length, input.length);
}

TEST_F(LibTestFixture, TEST-NAME) {
    // Your test
}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}