{
	'targets': [
		{
			'target_name': 'addon',
			'sources': [
				'src/main.cc',
				'src/myobject.cc'
			],
			'conditions': [
				['OS=="win"', 
					{'libraries': ['-lnode.lib']}
				]
			]
		}
		
	]
}
