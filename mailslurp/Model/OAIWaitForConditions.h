#import <Foundation/Foundation.h>
#import "OAIObject.h"

/**
* MailSlurp API
* MailSlurp is an API for sending and receiving emails from dynamically allocated email addresses. It's designed for developers and QA teams to test applications, process inbound emails, send templated notifications, attachments, and more.  ## Resources  - [Homepage](https://www.mailslurp.com) - Get an [API KEY](https://app.mailslurp.com/sign-up/) - Generated [SDK Clients](https://www.mailslurp.com/docs/) - [Examples](https://github.com/mailslurp/examples) repository
*
* The version of the OpenAPI document: 6.5.2
* Contact: contact@mailslurp.dev
*
* NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
* https://openapi-generator.tech
* Do not edit the class manually.
*/


#import "OAIMatchOption.h"
@protocol OAIMatchOption;
@class OAIMatchOption;



@protocol OAIWaitForConditions
@end

@interface OAIWaitForConditions : OAIObject


@property(nonatomic) NSString* inboxId;
/* Number of results that should match conditions. Either exactly or at least this amount based on the `countType`. If count condition is not met and the timeout has not been reached the `waitFor` method will retry the operation. [optional]
 */
@property(nonatomic) NSNumber* count;
/* Max time in milliseconds to wait between retries if a `timeout` is specified. [optional]
 */
@property(nonatomic) NSNumber* delayTimeout;
/* Max time in milliseconds to retry the `waitFor` operation until conditions are met. 
 */
@property(nonatomic) NSNumber* timeout;
/* Apply conditions only to **unread** emails. All emails begin with `read=false`. An email is marked `read=true` when an `EmailDto` representation of it has been returned to the user at least once. For example you have called `getEmail` or `waitForLatestEmail` etc., or you have viewed the email in the dashboard. [optional]
 */
@property(nonatomic) NSNumber* unreadOnly;
/* How result size should be compared with the expected size. Exactly or at-least matching result? [optional]
 */
@property(nonatomic) NSString* countType;

@property(nonatomic) NSArray<OAIMatchOption>* matches;

@property(nonatomic) NSString* sortDirection;

@property(nonatomic) NSDate* since;

@property(nonatomic) NSDate* before;

@end
