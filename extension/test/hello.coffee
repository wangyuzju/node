###

hello = require '../build/Release/hello.node'

console.log hello.greet('wangyu')


echo = ()->
	
	Array.prototype.forEach.call(arguments, (item, i)->
		console.log "[#{i}]" + item
	)


hello.run(echo)

console.log hello.newPeople('MCY')

console.log hello.getFn()()

###
hello = require '../build/Release/hello.node'

console.log(hello.print())