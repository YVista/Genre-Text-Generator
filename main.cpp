//
//  main.cpp
//  Genre Text Generator
//  Created by Y.Vista on 16/11/27.
//  Copyright © 2016年 Y.Vista. All rights reserved.
//

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include "gufeng baixue.h"
using namespace std;

#define ARR_LEN(array, length){ length =  sizeof(array) / sizeof(array[0]); }
int main()
{       int ch1_len, ch2_len, ch4_len, sen_len;
    string ch1_ran, ch2_ran, ch4_ran, sen_ran;
    ARR_LEN(ch1, ch1_len);
    ARR_LEN(ch2, ch2_len);
    ARR_LEN(ch4, ch4_len);
    ARR_LEN(sen, sen_len);
    int sen_t, ch1_t, ch2_t, ch4_t;
    cout<<"按回车键继续生成，按其他键加回车退出"<<endl;
    while( getchar()=='\n')
    {   srand(time(0));       // 种子
        sen_t = rand() % sen_len;       // 给sen的随机序数
        sen_ran=sen[sen_t]; //sen中的随机项
        string::size_type pos_ch4=sen_ran.find("xxxx");
        while (pos_ch4 != string::npos)
        {   ch4_t = rand() % ch4_len;       // 给ch4的随机序数
            ch4_ran=ch4[ch4_t]; // ch4中的随机项
            sen_ran = sen_ran.replace(sen_ran.find("xxxx"), 4, ch4_ran); //从第一个xxxx位置替换第一个xxxx为ch4
            pos_ch4=sen_ran.find("xxxx");
        }
        string::size_type pos_ch2=sen_ran.find("xx");
        while (pos_ch2 != string::npos)
        {   ch2_t = rand() % ch2_len;       // 给ch2的随机序数
            ch2_ran=ch2[ch2_t]; // ch2中的随机项
            sen_ran = sen_ran.replace(sen_ran.find("xx"), 2, ch2_ran); //从第一个xx位置替换第一个xx为ch2
            pos_ch2=sen_ran.find("xx");
        }
        string::size_type pos_ch1=sen_ran.find("x");
        while (pos_ch1 != string::npos)
        {   ch1_t = rand() % ch1_len;       // 给ch1的随机序数
            ch1_ran=ch1[ch1_t]; // ch1中的随机项
            sen_ran = sen_ran.replace(sen_ran.find("x"), 1, ch1_ran); //从第一个x位置替换第一个x为ch1
            pos_ch1=sen_ran.find("x");
        }
        cout << sen_ran << endl;
    }
    return 0;
}
