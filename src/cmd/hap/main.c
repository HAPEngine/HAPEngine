#include <hap.h>

int main(int argc, char *argv[]) {
  HAPEngine *engine = hap_engine_create("HAP", NULL);
  if (engine == NULL) return 1;

  hap_engine_destroy(engine);
  return 0;
}
