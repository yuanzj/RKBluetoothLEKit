//
//  RKPackage.h
//  RokyinfoBLEDemo
//
//  Created by apple on 16/3/10.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RKPackage : NSObject

@property (nonatomic,assign) short packageIndex;

@property (nonatomic,assign) int   packageSize;

@property (nonatomic,assign) int   uploadLength;

@property (nonatomic,assign) short crc;

@end
