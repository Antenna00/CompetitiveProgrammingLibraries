#include <string>
#ifdef _LOCAL
static const char* pthread_path = "";
#else
static const char* pthread_path = "/lib/x86_64-linux-gnu/libpthread.so.0";
#endif // _LOCAL

extern "C" void* __libc_dlopen_mode(const char* x, int y);
extern "C" void* __libc_dlsym(void* x, const char* y);

struct dynamic_link_library {
    void* handle;
    dynamic_link_library(const char* path)
        : handle(__libc_dlopen_mode(path, 2))
    {
    }

    void* operator()(const char* symbol) {
        return __libc_dlsym(handle, symbol);
    }
};
dynamic_link_library pthread_handle(pthread_path);
extern "C" {
    int pthread_create(
        pthread_t*            __restrict __newthread,
        const pthread_attr_t* __restrict __attr     ,
        void*              (*__start_routine)(void*),
        void*                 __restrict __arg
    ) {
        typedef decltype(pthread_create) (*type);
        static type ptr = reinterpret_cast<type>(pthread_handle("pthread_create"));
        return ptr(__newthread, __attr, __start_routine, __arg);
    }

    void pthread_exit(void* __retval) {
        typedef decltype(pthread_exit) (*type);
        static type ptr = reinterpret_cast<type>(pthread_handle("pthread_exit"));
        return ptr(__retval);
    }

    int pthread_join(pthread_t __th, void** __thread_return) {
        typedef decltype(pthread_join) (*type);
        static type ptr = reinterpret_cast<type>(pthread_handle("pthread_join"));
        return ptr(__th, __thread_return);
    }

    int pthread_detatch(pthread_t __th) {
        typedef decltype(pthread_detatch) (*type);
        static type ptr = reinterpret_cast<type>(pthread_handle("pthread_detatch"));
        return ptr(__th);
    }
}
