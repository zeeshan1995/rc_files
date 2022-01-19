#include <iostream>

int main()

{
    std::cout <<"SENIOR SECONDARY EXAMINATION 2020" << std::endl;
    
    std::cout<<"Enter Your Marks"<< std::endl;
    
    std::cout<<"Marks Obtained in Physics:";
    int physics_marks;
    std::cin >> physics_marks;
    
    std::cout<<"Marks Obtained In Chemistry:";
    int chemistry_marks;
    std::cin>> chemistry_marks;
    
    std::cout<<"Marks Obtained in Maths:";
    int maths_marks;
    std::cin>> maths_marks;
    
    std::cout<<"Marks Obtained in English:";
    int english_marks;
    std::cin>> english_marks;
    
    std::cout << "Marks Obtained in PHE/IP:";
    int ip_marks;
    std::cin >> ip_marks;
    
    int total_marks = physics_marks 
                    + chemistry_marks
                    + maths_marks
                    + english_marks
                    + ip_marks;
    
    std::cout << "TOTAL MARKS OBTAINED:" << total_marks << std::endl;
    
    int percent = total_marks * 100 / 500 ;
    
    std::cout<<"PERCENTAGE OBTAINED:" << percent <<"%" <<std::endl;


    /*
    ==
    <
    >
    <=
    >=
    */

    /*
    and
    or
    xor
    */

    bool fail = (2 <= 3);
    /*
    if((maths_marks < 33) or (physics_marks < 33) or (chemistry_marks < 33) or (english_marks < 33) or (ip_marks < 33))
    {
        std::cout << "FAIL" << std::endl;
    }
    else
    {
        std::cout << "PASS" << std::endl;
    }
    */

    bool pass = true;
    int subject_fail = 0;

    if(maths_marks < 33)
    {
        std::cout << "FAIL in maths" << std::endl;
        pass = false;
        subject_fail = subject_fail + 1;
    }

    if(physics_marks < 33)
    {
        std::cout << "FAIL in physics" << std::endl;
        pass = false;
        subject_fail = subject_fail + 1;
    }

    if(english_marks < 33)
    {
        std::cout << "FAIL in english" << std::endl;
        pass = false;
        subject_fail = subject_fail + 1;
    }
    if(chemistry_marks < 33)
    {
        std::cout << "FAIL in chemistry" << std::endl;
        pass = false;
        subject_fail = subject_fail + 1;
    }

    if(ip_marks < 33)
    {
        std::cout << "FAIL in ip" << std::endl;
        pass = false;
        subject_fail = subject_fail + 1;
    }


    if(pass == true)
    {
        std::cout << "PASS" << std::endl;
    }
    else
    {
        if(subject_fail > 1)
        {
            std::cout <<"FAIL without compart" << std::endl;
        }
        else
        {
            std::cout << "FAIL with comaprt" << std::endl;
        }
    }
}
