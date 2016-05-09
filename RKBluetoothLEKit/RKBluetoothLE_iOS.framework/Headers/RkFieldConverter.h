//
//  RkFieldConverter.h
//  RokyinfoBLEDemo
//
//  Created by apple on 16/5/5.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ByteConvert.h"

@protocol RkFieldConverter <NSObject>

@optional
-(NSData*)entity2bytes;

@required
-(id)bytes2entity:(NSData*)data;

@end
