#import <Foundation/Foundation.h>
#import "OAIMissedEmail.h"
#import "OAIPageMissedEmailProjection.h"
#import "OAIPageUnknownMissedEmailProjection.h"
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



@interface OAIMissedEmailControllerApi: NSObject <OAIApi>

extern NSString* kOAIMissedEmailControllerApiErrorDomain;
extern NSInteger kOAIMissedEmailControllerApiMissingParamErrorCode;

-(instancetype) initWithApiClient:(OAIApiClient *)apiClient NS_DESIGNATED_INITIALIZER;

/// Get all MissedEmails in paginated format
/// 
///
/// @param page Optional page index in list pagination (optional) (default to @0)
/// @param size Optional page size in list pagination (optional) (default to @20)
/// @param sort Optional createdAt sort direction ASC or DESC (optional) (default to @"ASC")
/// @param searchFilter Optional search filter (optional)
/// @param since Filter by created at after the given timestamp (optional)
/// @param before Filter by created at before the given timestamp (optional)
/// @param inboxId Optional inbox ID filter (optional)
/// 
///  code:200 message:"OK"
///
/// @return OAIPageMissedEmailProjection*
-(NSURLSessionTask*) getAllMissedEmailsWithPage: (NSNumber*) page
    size: (NSNumber*) size
    sort: (NSString*) sort
    searchFilter: (NSString*) searchFilter
    since: (NSDate*) since
    before: (NSDate*) before
    inboxId: (NSString*) inboxId
    completionHandler: (void (^)(OAIPageMissedEmailProjection* output, NSError* error)) handler;


/// Get all unknown missed emails in paginated format
/// Unknown missed emails are emails that were sent to MailSlurp but could not be assigned to an existing inbox.
///
/// @param page Optional page index in list pagination (optional) (default to @0)
/// @param size Optional page size in list pagination (optional) (default to @20)
/// @param sort Optional createdAt sort direction ASC or DESC (optional) (default to @"ASC")
/// @param searchFilter Optional search filter (optional)
/// @param since Filter by created at after the given timestamp (optional)
/// @param before Filter by created at before the given timestamp (optional)
/// @param inboxId Optional inbox ID filter (optional)
/// 
///  code:200 message:"OK"
///
/// @return OAIPageUnknownMissedEmailProjection*
-(NSURLSessionTask*) getAllUnknownMissedEmailsWithPage: (NSNumber*) page
    size: (NSNumber*) size
    sort: (NSString*) sort
    searchFilter: (NSString*) searchFilter
    since: (NSDate*) since
    before: (NSDate*) before
    inboxId: (NSString*) inboxId
    completionHandler: (void (^)(OAIPageUnknownMissedEmailProjection* output, NSError* error)) handler;


/// Get MissedEmail
/// 
///
/// @param missedEmailId 
/// 
///  code:200 message:"OK"
///
/// @return OAIMissedEmail*
-(NSURLSessionTask*) getMissedEmailWithMissedEmailId: (NSString*) missedEmailId
    completionHandler: (void (^)(OAIMissedEmail* output, NSError* error)) handler;


/// Wait for Nth missed email
/// Wait for 0 based index missed email
///
/// @param index Zero based index of the email to wait for. If 1 missed email already and you want to wait for the 2nd email pass index&#x3D;1
/// @param inboxId Optional inbox ID filter (optional)
/// @param timeout Optional timeout milliseconds (optional)
/// @param since Filter by created at after the given timestamp (optional)
/// @param before Filter by created at before the given timestamp (optional)
/// 
///  code:200 message:"OK"
///
/// @return OAIMissedEmail*
-(NSURLSessionTask*) waitForNthMissedEmailWithIndex: (NSNumber*) index
    inboxId: (NSString*) inboxId
    timeout: (NSNumber*) timeout
    since: (NSDate*) since
    before: (NSDate*) before
    completionHandler: (void (^)(OAIMissedEmail* output, NSError* error)) handler;



@end
