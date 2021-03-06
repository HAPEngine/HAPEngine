#include <hap.h>
#include <stdio.h>


typedef struct HAPModule HAPModule;


/** Module lifecycle **/
HAPModule* hap_module_create(char *identifier, HAPEngine *engine, HAPConfigurationSection *configuration);
void hap_module_load(HAPEngine *engine, HAPModule *module);
HAPTime hap_module_update(HAPEngine *engine, HAPModule *module);
void hap_module_render(HAPEngine *engine, HAPModule *module);
void hap_module_unload(HAPEngine *engine, HAPModule *module);
void hap_module_destroy(HAPEngine *engine, HAPModule *module);


struct HAPModule {
    char *identifier;
    void *ref;
    void *state;

    HAPTime nextUpdate;

    void* (*create)(HAPEngine *engine, HAPConfigurationSection *configuration);
    void (*load)(HAPEngine *engine, void *state, char *identifier);
    HAPTime (*update)(HAPEngine *engine, void* state);
    void (*render)(HAPEngine *engine, void* state);
    void (*unload)(HAPEngine *engine, void* state);
    void (*destroy)(HAPEngine *engine, void* state);
};
