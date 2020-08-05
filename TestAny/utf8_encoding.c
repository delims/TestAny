//
//  utf8_encoding.c
//  TestAny
//
//  Created by delims on 2020/8/5.
//  Copyright © 2020 delims. All rights reserved.
//

#include "utf8_encoding.h"

//根据汉子Unicode编码号获取在计算机中真实存储的byte
int realBytesFromUnicode(int code)
{
    //三个字节的情况
    if (0x10000 > code && code > 0x100*8)
    {
        int byte1 = (code & 0xf000) >> 12;
        int byte2 = (code & 0xfc0) << 2;
        int byte3 = (code & 0x3f) << 16;
        
        byte1 += 0xe0;
        byte2 += 0x8000;
        byte3 += 0x800000;

        int result = byte1 + byte2 + byte3;
        return result;
    }
    return 0;
}

void uft8_encoding(void)
{
    
//unicode 字节数对应的有效位数
// 1-2^7, 2-2^11, 3-2^16, 4-2^21, 5-2^26, 6-2^31
                    
    for (int i = 0x4E00; i < 0x9FA5; i ++) {
        int word = realBytesFromUnicode(i);
        printf("0x%x=%s  ",i,(char*)&word);
    }
    
    
}
