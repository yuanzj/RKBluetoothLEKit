//
//  RKFirstViewController.m
//  RKBluetoothLEKit
//
//  Created by apple on 16/7/19.
//  Copyright © 2016年 yuanzj. All rights reserved.
//

#import "RKFirstViewController.h"
#import "ScanViewController.h"
#import "RKTableViewController.h"
#import "RACSignal.h"
#import "RACScheduler.h"
#import "RACSignal+Operations.h"
#import "RACDisposable.h"
#import "RACSubscriber.h"

@interface RKFirstViewController ()<ScanViewControllerDelegate>{
    
    BOOL isScanOk;

}

@property(nonatomic,weak)IBOutlet UITextField *mUITextField;

@end

@implementation RKFirstViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    isScanOk = NO;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void)viewWillAppear:(BOOL)animated{
    
    [super viewWillAppear:animated];
    if (isScanOk) {
        
        [[[RACSignal createSignal:^RACDisposable *(id subscriber) {
            [subscriber sendNext:nil];
            [subscriber sendCompleted];
            return nil;
        }] delay:1] subscribeNext:^(id x) {
           [self performSegueWithIdentifier:@"enterTestList" sender:self];
        }];
        
    }
    
}

-(void)scanReult:(NSString*)value{
    
    NSArray<NSString*> *data = [value componentsSeparatedByString:@" "];
    if (data.count >= 3) {
        NSUserDefaults *user = [NSUserDefaults standardUserDefaults];
        [user setObject:data[0] forKey:@"SN"];
        [user setObject:data[1] forKey:@"MAC"];
        [user setObject:data[2] forKey:@"AUTH"];
        [user synchronize];
        isScanOk = YES;
        [self.navigationController popViewControllerAnimated:YES];
    }
}

-(IBAction)enterIntoTestList:(id)sender{
    if(self.mUITextField.text.length > 0){
        
        NSUserDefaults *user = [NSUserDefaults standardUserDefaults];
        [user setObject:self.mUITextField.text forKey:@"SN"];
        [user synchronize];
        isScanOk = YES;

        [self performSegueWithIdentifier:@"enterTestList" sender:sender];
    }
}

#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
    if ([segue.identifier isEqualToString:@"enterTestList"]) {
//        UIViewController *mUIViewController = [segue destinationViewController];
         isScanOk = NO;
    } else  if ([segue.identifier isEqualToString:@"scan"])  {
        ScanViewController *mUIViewController = [segue destinationViewController];
        mUIViewController.delegate = self;
    }
    
}


@end
