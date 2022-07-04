#import <Foundation/Foundation.h>
#import "OAIPageSmsProjection.h"
#import "OAISmsMessage.h"
#import "OAIApi.h"

/**
* MailSlurp API
* MailSlurp is an API for sending and receiving emails from dynamically allocated email addresses. It's designed for developers and QA teams to test applications, process inbound emails, send templated notifications, attachments, and more.  ## Resources  - [Homepage](https://www.mailslurp.com) - Get an [API KEY](https://app.mailslurp.com/sign-up/) - Generated [SDK Clients](https://docs.mailslurp.com/) - [Examples](https://github.com/mailslurp/examples) repository
*
* The version of the OpenAPI document: 6.5.2
* Contact: contact@mailslurp.dev
*
* NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
* https://openapi-generator.tech
* Do not edit the class manually.
*/



@interface OAISmsControllerApi: NSObject <OAIApi>

extern NSString* kOAISmsControllerApiErrorDomain;
extern NSInteger kOAISmsControllerApiMissingParamErrorCode;

-(instancetype) initWithApiClient:(OAIApiClient *)apiClient NS_DESIGNATED_INITIALIZER;

/// Delete SMS message.
/// Delete an SMS message
///
/// @param smsId 
/// 
///  code:204 message:"No Content"
///
/// @return void
-(NSURLSessionTask*) deleteSmsMessageWithSmsId: (NSString*) smsId
    completionHandler: (void (^)(NSError* error)) handler;


/// Delete all SMS messages
/// Delete all SMS messages or all messages for a given phone number
///
/// @param phoneNumberId  (optional)
/// 
///  code:204 message:"No Content"
///
/// @return void
-(NSURLSessionTask*) deleteSmsMessagesWithPhoneNumberId: (NSString*) phoneNumberId
    completionHandler: (void (^)(NSError* error)) handler;


/// Get SMS content including body. Expects SMS to exist by ID. For SMS that may not have arrived yet use the WaitForController.
/// Returns a SMS summary object with content.
///
/// @param smsId 
/// 
///  code:200 message:"OK"
///
/// @return OAISmsMessage*
-(NSURLSessionTask*) getSmsMessageWithSmsId: (NSString*) smsId
    completionHandler: (void (^)(OAISmsMessage* output, NSError* error)) handler;


/// Get all SMS messages in all phone numbers in paginated form. .
/// By default returns all SMS messages across all phone numbers sorted by ascending created at date. Responses are paginated. You can restrict results to a list of phone number IDs. You can also filter out read messages
///
/// @param phoneNumber Optional receiving phone number to filter SMS messages for (optional)
/// @param page Optional page index in SMS list pagination (optional) (default to @0)
/// @param size Optional page size in SMS list pagination. Maximum size is 100. Use page index and sort to page through larger results (optional) (default to @20)
/// @param sort Optional createdAt sort direction ASC or DESC (optional) (default to @"ASC")
/// @param unreadOnly Optional filter for unread SMS only. All SMS are considered unread until they are viewed in the dashboard or requested directly (optional) (default to @(NO))
/// @param since Optional filter SMSs received after given date time (optional)
/// @param before Optional filter SMSs received before given date time (optional)
/// 
///  code:200 message:"OK"
///
/// @return OAIPageSmsProjection*
-(NSURLSessionTask*) getSmsMessagesPaginatedWithPhoneNumber: (NSString*) phoneNumber
    page: (NSNumber*) page
    size: (NSNumber*) size
    sort: (NSString*) sort
    unreadOnly: (NSNumber*) unreadOnly
    since: (NSDate*) since
    before: (NSDate*) before
    completionHandler: (void (^)(OAIPageSmsProjection* output, NSError* error)) handler;



@end
