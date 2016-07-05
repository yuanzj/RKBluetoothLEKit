//
//  RSA.h
//  RokyinfoBLEDemo
//
//  Created by apple on 16/7/4.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RSA : NSObject

-(instancetype)initWithPrivatKey:(NSData*)key password:(NSString*)psw;

- (NSData*)rsaDecryptData:(NSData*)data;

@end
