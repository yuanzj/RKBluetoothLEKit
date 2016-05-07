//
//  Response.h
//  RokyinfoBLEDemo
//
//  Created by apple on 16/3/30.
//  Copyright © 2016年 rokyinfo. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Response<ObjectType> : NSObject

@property (nonatomic,copy,readonly) NSError    *error;

@property (nonatomic,copy,readonly) ObjectType result;

+(Response*)success:(ObjectType)value;

+(Response*)error:(NSError*)error;

-(BOOL)isSuccess;

@end
