#include <hap.h>

#include "logging.h"
#include "module.h"
#include "timer.h"


HAPEngine* hap_engine_create(char *name, char *configuration) {
    if (name == NULL)
        name = "HAP";

    if (configuration == NULL)
        configuration = "system";

    HAPEngine *engine = calloc(1, sizeof(HAPEngine));

    if (engine == NULL) return NULL;

    (*engine).name = name;
    (*engine).time = hap_timer_update((*engine).time);
    (*engine).logLevel = LOGLEVEL_INFO;

    (*engine).log = hap_log;
    (*engine).log_debug = hap_log_debug;
    (*engine).log_info = hap_log_info;
    (*engine).log_notice = hap_log_notice;
    (*engine).log_warning = hap_log_warning;
    (*engine).log_error = hap_log_error;
    (*engine).log_fatal_error = hap_log_fatal_error;

    (*engine).log_info(engine, "Initializing");

    (*engine).configuration = hap_configuration_load(engine, configuration);

    (*engine).isRunning = true;

    if ((*engine).configuration == NULL) {
        free(engine);
        return NULL;
    }

    return engine;
}


void hap_engine_destroy(HAPEngine *engine) {
    hap_timer_destroy((*engine).time);
    (*engine).log_notice(engine, "Terminating engine");
    free(engine);
}
