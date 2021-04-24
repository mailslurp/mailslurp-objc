#import <Foundation/Foundation.h>
#import "OAIObject.h"

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


#import "OAIValidationMessage.h"
@protocol OAIValidationMessage;
@class OAIValidationMessage;



@protocol OAIHTMLValidationResult
@end

@interface OAIHTMLValidationResult : OAIObject

/* Optional errors resulting from HTML validation [optional]
 */
@property(nonatomic) NSArray<OAIValidationMessage>* errors;
/* Is HTML validation result valid [optional]
 */
@property(nonatomic) NSNumber* isValid;
/* Optional warnings resulting from HTML validation [optional]
 */
@property(nonatomic) NSArray<OAIValidationMessage>* warnings;

@end
