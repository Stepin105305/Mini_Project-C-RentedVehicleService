/**
* @file testlogin.c
*/
/**
*This C file is written to automatically test the required cases in the project.
*/

#include "unity.h"


void setUp()
{

}
void tearDown()
{

}
/**
*This function checks the login conditions with correct userid and password.
*If the function is returned 1 then the test case is passed.
*/
void test_login_correct(void)
{
    TEST_ASSERT_EQUAL(1,login(105305,105305));
}
/**
*This function checks the login conditions with incorrect userid and password.
*If the function is returned 2 then the test case is passed.
*/
void test_login_wrong(void)
{
    TEST_ASSERT_EQUAL(2,login(105305,105304));
}
/**
*This function passes the unique vehicle number that is to be booked along with the required details.
*If the function is returned 1 then the test case is passed.
*/
void rent_correct_vehicle(void)
{
     TEST_ASSERT_EQUAL(1,rents(9,"Ram","Joshi","643312328956","987456123","ram@gmail.com"));
     TEST_ASSERT_EQUAL(1,rents(10,"Shreesh","Joshi","785645852356","866088950","shreesh@gmail.com"));
     TEST_ASSERT_EQUAL(1,rents(11,"Rahul","Hubli","564523659878","741118585","rahul@gmail.com"));
}
/**
*This function passes the already booked vehicle number to be book along with the required details.
*If the function is returned 2 then the test case is passed.
*/
void rent_rented_vehicle(void)
{
     TEST_ASSERT_EQUAL(2,rents(9,"Rahul","Joshi","785645852356","741118585","rahul@gmail.com"));
}
/**
*This function passes the valid vehicle number to be searched that is present in the record.
*If the function is returned 1 then the test case is passed.
*/

void search_correct_vehicle(void)
{
    TEST_ASSERT_EQUAL(1,search(9));
}
/**
*This function passes the invalid vehicle number which is not present in the record.
*If the function is returned 2 then the test case is passed.
*/
void search_wrong_vehicle(void)
{
    TEST_ASSERT_EQUAL(2,search(25));
}
/**
*This function passes the valid vehicle number to be deleted that is present in the record.
*If the function is returned 1 then the test case is passed.
*/
void delete_correct_vehicle(void)
{   TEST_ASSERT_EQUAL(1,rents(6,"Shri","Hari","123456789","9876543210","acb@gmail.com"));
    TEST_ASSERT_EQUAL(1,delet(9));
}
/**
*This function passes the invalid vehicle number which is not present in the record.
*If the function is returned 2 then the test case is passed.
*/
void delete_wrong_vehicle(void)
{
    TEST_ASSERT_EQUAL(2,delet(25));
}
/**
*This function passes the valid vehicle number to be edited that is present in the record.
*If the function is returned 1 then the test case is passed.
*/
void edit_correct_vehicle(void)
{
    TEST_ASSERT_EQUAL(1,edit(6,"Sourabh","Chinchani","874512987515","990296990","sourabh@gmail.com"));

}
/**
*This function passes the invalid vehicle number which is not present in the record.
*If the function is returned 2 then the test case is passed.
*/
void edit_wrong_vehicle(void)
{
    TEST_ASSERT_EQUAL(2,edit(25,"Shri","Hari","123456789","987654321","abc@gmail.com"));
}
/**
*This command is used to view the record
*/
void view_correct(void)
{
    TEST_ASSERT_EQUAL(1,view());
}
/**
*This is the main function that runs all the test cases.
*/
int test_main(void)
{

    UNITY_BEGIN();
    RUN_TEST(test_login_correct);
    RUN_TEST(test_login_wrong);
    RUN_TEST(rent_correct_vehicle);
    RUN_TEST(rent_rented_vehicle);
    RUN_TEST(search_correct_vehicle);
    RUN_TEST(delete_correct_vehicle);
    RUN_TEST(delete_wrong_vehicle);
    RUN_TEST(edit_correct_vehicle);
    RUN_TEST(edit_wrong_vehicle);
    RUN_TEST(view_correct);
    return UNITY_END();
}
