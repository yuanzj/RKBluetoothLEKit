//
//  ByteConvert.h
//  车精灵
//
//  Created by apple on 15/5/14.
//  Copyright (c) 2015年 无锡锐祺. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ByteConvert : NSObject
+ (int) bytesToUint:(Byte[]) array ;
+ (int) bytesToUshort:(Byte[]) b offset:(int) offset;
+ (int) bytesToUshort:(Byte[]) b;
+ (int) getBitValue:(int) num index:( int) index;

+ (NSData*) intToBytes:(int) n;
+ (NSData*) shortToBytes:(int) n;

@end
