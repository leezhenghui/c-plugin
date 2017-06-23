{
  'includes': [ 'common.gypi' ],
  'targets': [
    {
      'target_name': 'main',
      'type': 'executable',
      'sources': [
        './src/main.c',
      ],
			'include_dirs': [
			  './src/hello_world.h',
			  './src/module.h',
		    './deps/simplelogger/simplog.h'	
			],
			'conditions': [
				['OS=="linux"', {
					'link_settings': {
						'libraries': [
							'-ldl'	
						]	
					},
					'ldflags': [
						'-rdynamic'
					],
				}],
			],
      'dependencies': [
        './deps/simplelogger.gyp:simplelogger'
      ]
    },
    {
      'target_name': 'svc_discovery',
      'type': 'static_library',
      'sources': [
        './src/svc_discovery.h',
        './src/svc_discovery.c'
      ],
			'include_dirs': [
		    './deps/simplelogger'	
			]
    },
    {
      'target_name': 'helloworld_en',
      'type': 'shared_library',
      'sources': [
        './src/hello_world_en.c'
      ],
			'cflags': [
				 '-fPIC'
			],
			'ldflags': [
			  '-shared'
			],
			'include_dirs': [
			  './src/hellow_world.h',
		    './src/module.h',
		    './src/svc_discovery.h',
		    './deps/simplelogger'	
			]
    },
    {
      'target_name': 'helloworld_cn',
      'type': 'shared_library',
      'sources': [
        './src/hello_world_cn.c'
      ],
			'cflags': [
				 '-fPIC'
			],
			'ldflags': [
			  '-shared'
			],
			'include_dirs': [
			  './src/hellow_world.h',
		    './src/module.h',
		    './src/svc_discovery.h',
		    './deps/simplelogger'	
			]
    }
  ]
}
