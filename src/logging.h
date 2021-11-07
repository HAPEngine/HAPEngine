#include <hap.h>
#include <stdbool.h>

bool hap_log_debug(const HAPEngine *const engine, char *message, ...);
bool hap_log_info(const HAPEngine *const engine, char *message, ...);
bool hap_log_notice(const HAPEngine *const engine, char *message, ...);
bool hap_log_warning(const HAPEngine *const engine, char *message, ...);
bool hap_log_error(const HAPEngine *const engine, char *message, ...);
void hap_log_fatal_error(const HAPEngine *const engine, int code, char *message,
                         ...);

void hap_log(const HAPEngine *const engine, FILE *dest, char *message,
             va_list arguments);
