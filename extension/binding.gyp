{
	'targets': [
		{
			'target_name': 'hello',
			'sources': [
				'src/main.cc',
			],
			'outouts': [
				'../hello.node'
			],
			'conditions': [
				['OS=="win"', 
					{'libraries': ['-lnode.lib']}
				]
			]
		}
		
	]
}
