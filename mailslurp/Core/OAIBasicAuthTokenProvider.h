/** The `OAIBasicAuthTokenProvider` class creates a basic auth token from username and password.
 *
 * NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */

#import <Foundation/Foundation.h>

@interface OAIBasicAuthTokenProvider : NSObject

+ (NSString *)createBasicAuthTokenWithUsername:(NSString *)username password:(NSString *)password;

@end