#import <Foundation/Foundation.h>
#import "OAICreateTemplateOptions.h"
#import "OAIPageTemplateProjection.h"
#import "OAITemplateDto.h"
#import "OAITemplateProjection.h"
#import "OAIApi.h"

/**
* MailSlurp API
* MailSlurp is an API for sending and receiving emails from dynamically allocated email addresses. It's designed for developers and QA teams to test applications, process inbound emails, send templated notifications, attachments, and more.   ## Resources - [Homepage](https://www.mailslurp.com) - Get an [API KEY](https://app.mailslurp.com/sign-up/) - Generated [SDK Clients](https://www.mailslurp.com/docs/) - [Examples](https://github.com/mailslurp/examples) repository 
*
* The version of the OpenAPI document: 67c9a1eda264be4cfe0bb2c76151f0aadf0862bc
* 
*
* NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
* https://openapi-generator.tech
* Do not edit the class manually.
*/



@interface OAITemplateControllerApi: NSObject <OAIApi>

extern NSString* kOAITemplateControllerApiErrorDomain;
extern NSInteger kOAITemplateControllerApiMissingParamErrorCode;

-(instancetype) initWithApiClient:(OAIApiClient *)apiClient NS_DESIGNATED_INITIALIZER;

/// Create a Template
/// 
///
/// @param createTemplateOptions createTemplateOptions
/// 
///  code:201 message:"Created",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found"
///
/// @return OAITemplateDto*
-(NSURLSessionTask*) createTemplateWithCreateTemplateOptions: (OAICreateTemplateOptions*) createTemplateOptions
    completionHandler: (void (^)(OAITemplateDto* output, NSError* error)) handler;


/// Delete Template
/// 
///
/// @param templateId TemplateId
/// 
///  code:204 message:"No Content",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden"
///
/// @return void
-(NSURLSessionTask*) deleteTemplateWithTemplateId: (NSString*) templateId
    completionHandler: (void (^)(NSError* error)) handler;


/// Get all Templates in paginated format
/// 
///
/// @param page Optional page index in inbox list pagination (optional) (default to @0)
/// @param size Optional page size in inbox list pagination (optional) (default to @20)
/// @param sort Optional createdAt sort direction ASC or DESC (optional) (default to @"ASC")
/// 
///  code:200 message:"OK",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found"
///
/// @return OAIPageTemplateProjection*
-(NSURLSessionTask*) getAllTemplatesWithPage: (NSNumber*) page
    size: (NSNumber*) size
    sort: (NSString*) sort
    completionHandler: (void (^)(OAIPageTemplateProjection* output, NSError* error)) handler;


/// Get Template
/// 
///
/// @param templateId TemplateId
/// 
///  code:200 message:"OK",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found"
///
/// @return OAITemplateDto*
-(NSURLSessionTask*) getTemplateWithTemplateId: (NSString*) templateId
    completionHandler: (void (^)(OAITemplateDto* output, NSError* error)) handler;


/// Get all Templates
/// 
///
/// 
///  code:200 message:"OK",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found"
///
/// @return NSArray<OAITemplateProjection>*
-(NSURLSessionTask*) getTemplatesWithCompletionHandler: 
    (void (^)(NSArray<OAITemplateProjection>* output, NSError* error)) handler;



@end
