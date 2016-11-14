//
//  BCDDecode.h
//  RokyinfoBLEDemo
//
//  Created by apple on 16/9/20.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BCDDecode : NSObject

+(NSString*) bcd2Str1:(NSData*) bytes;

/**
 * @功能: BCD码转为10进制串(阿拉伯数据)
 * @参数: BCD码
 * @结果: 10进制串
 */
+(NSString*) bcd2Str:(NSData*) bytes;

/**
 * @功能: 10进制串转为BCD码
 * @参数: 10进制串
 * @结果: BCD码
 */
+(NSData*)str2Bcd:(NSString*)asc;


@end
