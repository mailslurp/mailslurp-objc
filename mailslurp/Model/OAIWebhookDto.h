#import <Foundation/Foundation.h>
#import "OAIObject.h"

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


#import "OAIWebhookHeaders.h"
@protocol OAIWebhookHeaders;
@class OAIWebhookHeaders;



@protocol OAIWebhookDto
@end

@interface OAIWebhookDto : OAIObject

/* ID of the Webhook 
 */
@property(nonatomic) NSString* _id;
/* User ID of the Webhook 
 */
@property(nonatomic) NSString* userId;
/* Does webhook expect basic authentication? If true it means you created this webhook with a username and password. MailSlurp will use these in the URL to authenticate itself. 
 */
@property(nonatomic) NSNumber* basicAuth;
/* Name of the webhook [optional]
 */
@property(nonatomic) NSString* name;
/* The phoneNumberId that the Webhook will be triggered by. If null then webhook triggered at account level or inbox level if inboxId set [optional]
 */
@property(nonatomic) NSString* phoneId;
/* The inbox that the Webhook will be triggered by. If null then webhook triggered at account level or phone level if phoneId set [optional]
 */
@property(nonatomic) NSString* inboxId;
/* Request body template for HTTP request that will be sent for the webhook. Use Moustache style template variables to insert values from the original event payload. [optional]
 */
@property(nonatomic) NSString* requestBodyTemplate;
/* URL of your server that the webhook will be sent to. The schema of the JSON that is sent is described by the payloadJsonSchema. 
 */
@property(nonatomic) NSString* url;
/* HTTP method that your server endpoint must listen for 
 */
@property(nonatomic) NSString* method;
/* Deprecated. Fetch JSON Schema for webhook using the getJsonSchemaForWebhookPayload method 
 */
@property(nonatomic) NSString* payloadJsonSchema;
/* When the webhook was created 
 */
@property(nonatomic) NSDate* createdAt;

@property(nonatomic) NSDate* updatedAt;
/* Webhook trigger event name [optional]
 */
@property(nonatomic) NSString* eventName;

@property(nonatomic) OAIWebhookHeaders* requestHeaders;

@end
