#import <Foundation/Foundation.h>
#import "OAICreateTrackingPixelOptions.h"
#import "OAIPageTrackingPixelProjection.h"
#import "OAITrackingPixelDto.h"
#import "OAIApi.h"

/**
* MailSlurp API
* MailSlurp is an API for sending and receiving emails from dynamically allocated email addresses. It's designed for developers and QA teams to test applications, process inbound emails, send templated notifications, attachments, and more.  ## Resources  - [Homepage](https://www.mailslurp.com) - Get an [API KEY](https://app.mailslurp.com/sign-up/) - Generated [SDK Clients](https://www.mailslurp.com/docs/) - [Examples](https://github.com/mailslurp/examples) repository 
*
* The version of the OpenAPI document: 6.5.2
* 
*
* NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
* https://openapi-generator.tech
* Do not edit the class manually.
*/



@interface OAITrackingControllerApi: NSObject <OAIApi>

extern NSString* kOAITrackingControllerApiErrorDomain;
extern NSInteger kOAITrackingControllerApiMissingParamErrorCode;

-(instancetype) initWithApiClient:(OAIApiClient *)apiClient NS_DESIGNATED_INITIALIZER;

/// Create tracking pixel
/// Create a tracking pixel
///
/// @param createTrackingPixelOptions createTrackingPixelOptions
/// 
///  code:201 message:"Created",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found"
///
/// @return OAITrackingPixelDto*
-(NSURLSessionTask*) createTrackingPixelWithCreateTrackingPixelOptions: (OAICreateTrackingPixelOptions*) createTrackingPixelOptions
    completionHandler: (void (^)(OAITrackingPixelDto* output, NSError* error)) handler;


/// Get tracking pixels
/// List tracking pixels in paginated form
///
/// @param page Optional page index in list pagination (optional) (default to @0)
/// @param size Optional page size in list pagination (optional) (default to @20)
/// @param sort Optional createdAt sort direction ASC or DESC (optional) (default to @"ASC")
/// 
///  code:200 message:"OK",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found"
///
/// @return OAIPageTrackingPixelProjection*
-(NSURLSessionTask*) getAllTrackingPixelsWithPage: (NSNumber*) page
    size: (NSNumber*) size
    sort: (NSString*) sort
    completionHandler: (void (^)(OAIPageTrackingPixelProjection* output, NSError* error)) handler;


/// Get pixel
/// 
///
/// @param _id id
/// 
///  code:200 message:"OK",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found"
///
/// @return OAITrackingPixelDto*
-(NSURLSessionTask*) getTrackingPixelWithId: (NSString*) _id
    completionHandler: (void (^)(OAITrackingPixelDto* output, NSError* error)) handler;



@end
