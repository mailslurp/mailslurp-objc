#import <Foundation/Foundation.h>
#import "OAIObject.h"

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


#import "OAIBasicAuthOptions.h"
@protocol OAIBasicAuthOptions;
@class OAIBasicAuthOptions;



@protocol OAICreateWebhookOptions
@end

@interface OAICreateWebhookOptions : OAIObject


@property(nonatomic) OAIBasicAuthOptions* basicAuth;
/* Optional webhook event name. Default is `EMAIL_RECEIVED`. Payload differ according to the webhook event name. [optional]
 */
@property(nonatomic) NSString* eventName;
/* Optional name for the webhook [optional]
 */
@property(nonatomic) NSString* name;
/* Public URL on your server that MailSlurp can post WebhookNotification payload to when an email is received. The payload of the submitted JSON is described by https://api.mailslurp.com/schemas/webhook-payload [optional]
 */
@property(nonatomic) NSString* url;

@end
