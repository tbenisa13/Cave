//
//  DataTypes.cpp
//  Practice1
//
//  Created by Taher Benisa on 5/22/22.
//  Copyright © 2022 taher benisa. All rights reserved.
//

#include "DataTypes.hpp"
#include <iostream>

using namespace std;

void dataTypes(void)
{
    {
        int i = 0x7fffffff; // Max positive number
        // Add 1 to i and see what happens: i=2147483647, i+1 = -2147483648
        cout << "Max positive number     = 0x7fffffff     = " << 0x7fffffff << endl;
        cout << "Max positive number + 1 = 0x7fffffff + 1 = " << 0x7fffffff + 1 << endl << endl;
        
        // Min negative number
        cout << "Min negative number     = 0x80000000     = "  << (int)0x80000000 << endl;
        cout << "Min negative number - 1 = 0x80000000 - 1 = " << (int)(0x80000000 - 1) << endl << endl;

        unsigned int ui = 0xffffffff;
        cout << ui << endl;
    }
    {
        float f =  33.5999000;
        double d = 33.5999000;
        printf("%20.20f", (9/5));
    }
    {
        char c1 = 257;//65536
        char c2 = 128;
        char c3 = c1 + c2;;
        cout << int(c3) << endl;
    }
    {
        int arr[] = {10, 20};
        int *p = arr;
        int x = *p++;   // Equivalent to *(p++)
        printf("arr[0] = %d, arr[1] = %d, *p = %d *p++ = %d\n", arr[0], arr[1], *p, x);
    }
    {
        unsigned int x = 4294967295; //(unsigned int)(0xffffffff);
        unsigned int y = 4294967295; //(unsigned int)(0xffffffff);
        unsigned int z = 0xffffffff + 0xffffffff;
        cout << z ;
    }

}
