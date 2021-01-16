#import <Foundation/Foundation.h>
#import "OAIAlias.h"
#import "OAIAliasDto.h"
#import "OAICreateAliasOptions.h"
#import "OAIPageAlias.h"
#import "OAIPageEmailProjection.h"
#import "OAIPageThreadProjection.h"
#import "OAIReplyToAliasEmailOptions.h"
#import "OAISendEmailOptions.h"
#import "OAISentEmailDto.h"
#import "OAIUpdateAliasOptions.h"
#import "OAIApi.h"

/**
* MailSlurp API
* MailSlurp is an API for sending and receiving emails from dynamically allocated email addresses. It's designed for developers and QA teams to test applications, process inbound emails, send templated notifications, attachments, and more.   ## Resources - [Homepage](https://www.mailslurp.com) - Get an [API KEY](https://app.mailslurp.com/sign-up/) - Generated [SDK Clients](https://www.mailslurp.com/docs/) - [Examples](https://github.com/mailslurp/examples) repository 
*
* The version of the OpenAPI document: 6.5.2
* 
*
* NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
* https://openapi-generator.tech
* Do not edit the class manually.
*/



@interface OAIAliasControllerApi: NSObject <OAIApi>

extern NSString* kOAIAliasControllerApiErrorDomain;
extern NSInteger kOAIAliasControllerApiMissingParamErrorCode;

-(instancetype) initWithApiClient:(OAIApiClient *)apiClient NS_DESIGNATED_INITIALIZER;

/// Create an email alias. Must be verified by clicking link inside verification email that will be sent to the address. Once verified the alias will be active.
/// Email aliases use a MailSlurp randomly generated email address (or a custom domain inbox that you provide) to mask or proxy a real email address. Emails sent to the alias address will be forwarded to the hidden email address it was created for. If you want to send a reply use the threadId attached
///
/// @param createAliasOptions createAliasOptions
/// 
///  code:201 message:"Created",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found"
///
/// @return OAIAliasDto*
-(NSURLSessionTask*) createAliasWithCreateAliasOptions: (OAICreateAliasOptions*) createAliasOptions
    completionHandler: (void (^)(OAIAliasDto* output, NSError* error)) handler;


/// Delete an email alias
/// 
///
/// @param aliasId aliasId
/// 
///  code:204 message:"No Content",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden"
///
/// @return void
-(NSURLSessionTask*) deleteAliasWithAliasId: (NSString*) aliasId
    completionHandler: (void (^)(NSError* error)) handler;


/// Get an email alias
/// Get an email alias by ID
///
/// @param aliasId aliasId
/// 
///  code:200 message:"OK",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found"
///
/// @return OAIAliasDto*
-(NSURLSessionTask*) getAliasWithAliasId: (NSString*) aliasId
    completionHandler: (void (^)(OAIAliasDto* output, NSError* error)) handler;


/// Get emails for an alias
/// Get paginated emails for an alias by ID
///
/// @param aliasId aliasId
/// @param page Optional page index alias email list pagination (optional) (default to @0)
/// @param size Optional page size alias email list pagination (optional) (default to @20)
/// @param sort Optional createdAt sort direction ASC or DESC (optional) (default to @"ASC")
/// 
///  code:200 message:"OK",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found"
///
/// @return OAIPageEmailProjection*
-(NSURLSessionTask*) getAliasEmailsWithAliasId: (NSString*) aliasId
    page: (NSNumber*) page
    size: (NSNumber*) size
    sort: (NSString*) sort
    completionHandler: (void (^)(OAIPageEmailProjection* output, NSError* error)) handler;


/// Get threads created for an alias
/// Returns threads created for an email alias in paginated form
///
/// @param aliasId aliasId
/// @param page Optional page index in thread list pagination (optional) (default to @0)
/// @param size Optional page size in thread list pagination (optional) (default to @20)
/// @param sort Optional createdAt sort direction ASC or DESC (optional) (default to @"ASC")
/// 
///  code:200 message:"OK",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found"
///
/// @return OAIPageThreadProjection*
-(NSURLSessionTask*) getAliasThreadsWithAliasId: (NSString*) aliasId
    page: (NSNumber*) page
    size: (NSNumber*) size
    sort: (NSString*) sort
    completionHandler: (void (^)(OAIPageThreadProjection* output, NSError* error)) handler;


/// Get all email aliases you have created
/// Get all email aliases in paginated form
///
/// @param page Optional page index in alias list pagination (optional) (default to @0)
/// @param size Optional page size in alias list pagination (optional) (default to @20)
/// @param sort Optional createdAt sort direction ASC or DESC (optional) (default to @"ASC")
/// 
///  code:200 message:"OK",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found"
///
/// @return OAIPageAlias*
-(NSURLSessionTask*) getAliasesWithPage: (NSNumber*) page
    size: (NSNumber*) size
    sort: (NSString*) sort
    completionHandler: (void (^)(OAIPageAlias* output, NSError* error)) handler;


/// Reply to an email
/// Send the reply to the email sender or reply-to and include same subject cc bcc etc. Reply to an email and the contents will be sent with the existing subject to the emails `to`, `cc`, and `bcc`.
///
/// @param aliasId ID of the alias that email belongs to
/// @param emailId ID of the email that should be replied to
/// @param replyToAliasEmailOptions replyToAliasEmailOptions
/// 
///  code:200 message:"OK",
///  code:201 message:"Created",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found"
///
/// @return OAISentEmailDto*
-(NSURLSessionTask*) replyToAliasEmailWithAliasId: (NSString*) aliasId
    emailId: (NSString*) emailId
    replyToAliasEmailOptions: (OAIReplyToAliasEmailOptions*) replyToAliasEmailOptions
    completionHandler: (void (^)(OAISentEmailDto* output, NSError* error)) handler;


/// Send an email from an alias inbox
/// Send an email from an alias. Replies to the email will be forwarded to the alias masked email address
///
/// @param aliasId aliasId
/// @param sendEmailOptions Options for the email to be sent (optional)
/// 
///  code:200 message:"OK",
///  code:201 message:"Created",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found"
///
/// @return OAISentEmailDto*
-(NSURLSessionTask*) sendAliasEmailWithAliasId: (NSString*) aliasId
    sendEmailOptions: (OAISendEmailOptions*) sendEmailOptions
    completionHandler: (void (^)(OAISentEmailDto* output, NSError* error)) handler;


/// Update an email alias
/// 
///
/// @param aliasId aliasId
/// @param updateAliasOptions updateAliasOptions
/// 
///  code:201 message:"Created",
///  code:202 message:"Accepted",
///  code:401 message:"Unauthorized",
///  code:403 message:"Forbidden",
///  code:404 message:"Not Found"
///
/// @return void
-(NSURLSessionTask*) updateAliasWithAliasId: (NSString*) aliasId
    updateAliasOptions: (OAIUpdateAliasOptions*) updateAliasOptions
    completionHandler: (void (^)(NSError* error)) handler;



@end
