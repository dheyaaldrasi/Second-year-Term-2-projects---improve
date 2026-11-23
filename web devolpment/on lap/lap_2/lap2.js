
let a = '10'
let b = 20
let c = true

console.log(a + b) // 1020

console.log(+a + b) // 30

console.log(Number(a) + b) // 30

console.log(a - b) // -10

console.log('' - b) // 0 - 20 = -20

console.log(+'') // 0

console.log(false - c) // -1

console.log(b + c) // 21

console.log(a + b + c) // 1020true

console.log(+a + b + c) // 31

let d = 10

d = d + 20

d = d + 30

d = d + 70

d += 100

console.log(d) // 230

console.log(1000000)

console.log(1_000_000)

console.log(10e9)

console.log(10 ** 9)

console.log(typeof Number) // function

console.log(Number.MAX_SAFE_INTEGER)

console.log(Number.MAX_SAFE_INTEGER + 1)

console.log(Number.MAX_SAFE_INTEGER)

console.log(Number.MAX_SAFE_INTEGER - 1)

console.log(Number.MAX_VALUE)

console.log(Number.MAX_VALUE + 1)

console.log(Number.MIN_VALUE)

console.log(Number.MIN_VALUE - 1) // -1

console.log(Number.MIN_VALUE + 1) // 1

console.log((100).toString()) // 100

console.log(100) // 100

console.log((100).toString()) // 100

console.log(100..toString()) // 100

console.log(100.0.toString()) // 100

console.log(100.28347238949287659287.toFixed(2)) // 100.28


console.log(parseInt('100')) // 100
console.log(parseInt('100.5')) // 100
console.log(parseInt('100 ls')) // 100
console.log(parseInt('s100')) // NaN
console.log(parseInt('1s00')) // 1


// ctrl + d


console.log(parseFloat('100')) // 100
console.log(parseFloat('100.5')) // 100
console.log(parseFloat('100 ls')) // 100
console.log(parseFloat('s100')) // NaN
console.log(parseFloat('1s00')) // 1

