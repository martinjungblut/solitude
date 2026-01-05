#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>

static __thread int depth;

__attribute__((no_instrument_function))
static void log_addr(const char *tag, void *fn, void *caller) {
    Dl_info info_fn = {0}, info_caller = {0};
    dladdr(fn, &info_fn);
    dladdr(caller, &info_caller);

    for (int i = 0; i < depth; i++) fputc(' ', stderr);
    fprintf(stderr, "%s %p %s :: caller %p %s\n",
            tag,
            fn, info_fn.dli_sname ? info_fn.dli_sname : "?",
            caller, info_caller.dli_sname ? info_caller.dli_sname : "?");
}

void __cyg_profile_func_enter(void *fn, void *caller)
    __attribute__((no_instrument_function));
void __cyg_profile_func_exit(void *fn, void *caller)
    __attribute__((no_instrument_function));

void __cyg_profile_func_enter(void *fn, void *caller) {
    log_addr("->", fn, caller);
    depth++;
}

void __cyg_profile_func_exit(void *fn, void *caller) {
    if (depth > 0) depth--;
    log_addr("<-", fn, caller);
}
