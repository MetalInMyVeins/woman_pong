def Settings(**kwargs):
    return{
            'flags':['-x', 'c++', '-std=c++20', '-g', '-Wall', '-Wextra', '-Wpedantic', '-Werror', '-Wno-unused-variable', '-Wno-unused-parameter', '-Wno-unused-private-field', '-I/usr/include/SDL2', '-Iinclude'],
            }
