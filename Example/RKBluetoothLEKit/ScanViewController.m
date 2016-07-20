//
//  ScanViewController.m
//  车精灵
//
//  Created by apple on 15/5/26.
//  Copyright (c) 2015年 无锡锐祺. All rights reserved.
//

#import "ScanViewController.h"

@interface ScanViewController ()<AVCaptureMetadataOutputObjectsDelegate>
@property (nonatomic, weak) IBOutlet UIView *scanRectView;

@property (nonatomic, weak) IBOutlet UIView *view1;
@property (nonatomic, weak) IBOutlet UIView *view2;
@property (nonatomic, weak) IBOutlet UIView *view3;
@property (nonatomic, weak) IBOutlet UIView *view4;

@property (nonatomic, strong) AVCaptureSession *captureSession;
@property (nonatomic, strong) AVCaptureVideoPreviewLayer *videoPreviewLayer;
@property (nonatomic, strong) AVCaptureMetadataOutput *captureMetadataOutput;

@end

@implementation ScanViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    [self startReading];
    
    [self.view bringSubviewToFront:self.scanRectView];
    
    [self.view bringSubviewToFront:self.view1];
    [self.view bringSubviewToFront:self.view2];
    [self.view bringSubviewToFront:self.view3];
    [self.view bringSubviewToFront:self.view4];
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (BOOL)startReading {
    NSError *error;
    
    AVCaptureDevice *captureDevice = [AVCaptureDevice defaultDeviceWithMediaType:AVMediaTypeVideo];
    
    AVCaptureDeviceInput *input = [AVCaptureDeviceInput deviceInputWithDevice:captureDevice error:&error];
    if (!input) {
        NSLog(@"%@", [error localizedDescription]);
        return NO;
    }
    
    self.captureSession = [[AVCaptureSession alloc] init];
    [self.captureSession addInput:input];
    
    _captureMetadataOutput = [[AVCaptureMetadataOutput alloc] init];
    [self.captureSession addOutput:_captureMetadataOutput];
    
    dispatch_queue_t dispatchQueue;
    dispatchQueue = dispatch_queue_create("myQueue", NULL);
    [_captureMetadataOutput setMetadataObjectsDelegate:self queue:dispatchQueue];
    [_captureMetadataOutput setMetadataObjectTypes:@[AVMetadataObjectTypeQRCode,AVMetadataObjectTypeCode39Code,AVMetadataObjectTypeCode128Code,AVMetadataObjectTypeCode39Mod43Code,AVMetadataObjectTypeEAN13Code,AVMetadataObjectTypeEAN8Code,AVMetadataObjectTypeCode93Code]];
    
//    CGRect metadataRect = [_videoPreviewLayer metadataOutputRectOfInterestForRect:self.scanRectView.frame];
//    _captureMetadataOutput.rectOfInterest = metadataRect;
    
    self.videoPreviewLayer = [[AVCaptureVideoPreviewLayer alloc] initWithSession:self.captureSession];
    [self.videoPreviewLayer setVideoGravity:AVLayerVideoGravityResizeAspectFill];
    [self.videoPreviewLayer setFrame:self.view.layer.bounds];

    [self.view.layer addSublayer:self.videoPreviewLayer];
    
    [self.captureSession startRunning];
    
    return YES;
}

-(void)stopReading{
    [self.captureSession stopRunning];
    self.captureSession = nil;
    
    [self.videoPreviewLayer removeFromSuperlayer];
    
   
}

-(void)captureOutput:(AVCaptureOutput *)captureOutput didOutputMetadataObjects:(NSArray *)metadataObjects fromConnection:(AVCaptureConnection *)connection{
    
    if (metadataObjects != nil && [metadataObjects count] > 0) {
        AVMetadataMachineReadableCodeObject *metadataObj = [metadataObjects objectAtIndex:0];
        
        dispatch_async(dispatch_get_main_queue(), ^{
            //输出结果
            NSString *stringValue = metadataObj.stringValue;
            NSLog(@"%@",stringValue);
            
            if (self.delegate) {
                [self.delegate scanReult:stringValue];
            }
            [self stopReading];
            [self.navigationController popViewControllerAnimated:YES];
        });

    }
}

-(void)dealloc{
    [self stopReading];
}
/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
