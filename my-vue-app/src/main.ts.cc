//定义number类型 看待类型就把它当成一个集合去看待
// type a_number = 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10;
// const a: a_number = 10

//定义字符串类型
// type a_string = 'a' | 'b' | 'c' | 'd' | 'e' | 'f' | 'g' | 'h' | 'i' | 'j' | 'k' | 'l' | 'm' | 'n' | 'o' | 'p' | 'q' | 'r' | 's' | 't' | 'u' | 'v' | 'w' | 'x' | 'y' | 'z'
// const b: a_string = 'a'
// console.log(b)

//定义布尔类型
// type a_boolean = true | false
// const c: a_boolean = true
// console.log(c)

//定义数组类型
// type a_array = Array<number>
// const d: a_array = [1, 2, 3, 4, 5]
// console.log(d)
//定义对象类型
// const d: object = { a: 1, b: 2, c: 3 }
// const d: {a: number, b: string,c: boolean} = { a: 1, b: '2', c: true }
// const d: {[key:number]: string} = { 1: 'a', 2: 'b', 3: 'c' } //这里的key是number类型的 但是值是string类型的 但是在JavaScript中对象的key是字符串类型的
// const s = Symbol('s')
// const d:Record<symbol, number> = {[s]: 1}
// type catList = '黑猫' | '白猫' | '红猫' | '绿猫'
// const cat: Record<catList, {name: string}> = {
//     '黑猫': { name: '黑猫' },
//     '白猫': { name: '白猫' },
//     '红猫': { name: '红猫' },
//     '绿猫': { name: '绿猫' },
// }
// console.log(cat)

//定义函数类型
// type a_function = (a: number, b: number) => void
// const e: a_function = (...args) => {
//     console.log(`${args}`)
// }
// e(1, 2)

// type Person = {
//     name: string,
//     age: number,
// }
// const xiaoming: Person = {
//     name: '小明',
//     age: 18
// }
// const withThisFn: (this: Person, a: number) => void = function (){
//     console.log(this.name)
// }
// withThisFn.call(xiaoming, 1)

//定义元组类型
// const f: [number, string] = [1, '2']
// const x: [number, string, boolean, undefined] = [1, '2', true, undefined]
// console.log(x)

//定义对象类型
// const g: object = { a: 1, b: 2, c: 3 }
// const g: {a: number, b: string,c: boolean} = { a: 1, b: '2', c: true }
// const z:RegExp = /ab+c/
// console.log(z.test('abbbbc'))
// const date: Date = new Date()
// console.log(date.toLocaleString())
//什么是 any? 任意类型 任意值 任意类型的值都可以赋值给它
// const a: any = 1
// const b: any = '2'
// const c: any = true
// console.log(a, b, c)

//什么是 unknown?  unknown 其实就是当前的这个值目前不确定, 比如从Ajax请求的数据的类型是不确定的,这时候就可以使用 unknown
// const a: unknown = 1
// const b = ( a as number)
// console.log(b)


//enum 枚举类型 用来定义一些常量的 一般用来定义一些状态
// enum Permission {
//     admin = 0, //0000
//     user = 1 << 0, //0001
//     vip = 1 << 1, //0010
//     superVip = 1 << 2, //0100
//     marge = admin | user | vip | superVip //0111
// }
//
// type User = {
//     permission: Permission
// }
//
// const user: User = {permission: 0b0010}
//
// if ((user.permission & Permission.vip) === Permission.vip) { // & 位运算符 两个都是1的时候才是1 有一个不是1的时候就是0 0010 & 0010 = 0010    0010 & 0001 = 0000
//     console.log('vip')
// }

//enum
// 需要枚举的值是字符串的时候 用enum
// 需要枚举的值是数字的时候 用enum
// 需要枚举的值是字符串和数字的时候 建议少用这种方式 用JavaScript中的对象来代替
// enum  除了数字和字符串之外 其他的数据类型值都不可以

//never类型例子
// function error(message: string): never {
//     throw new Error(message)
// }
//
// console.log(error('123'))

// interface A {
//     type: 'foo'
// }
//
// interface B {
//     type: 'bar'
// }
//
// type All = A | B
//
// const a: All = {type: 'foo'}
// const b: All = {type: 'bar'}
//
// if (a.type === 'foo') {
//     console.log(a.type)
// }else if (b.type === 'bar') {
//     console.log(b.type)
// }else {
//     const check: never = a
//     console.log(check)
// }

//联合类型例子
// type A1 = number
// type B1 = string
// type C1 = A1 | B1
// const a1: C1 = 1
// console.log(a1)

//联合类型例子
// type A2 = {a: number}
// type B2 = {b: string}
// type C2 = A2 | B2
// const a2: C2 = {a: 1,b: '2'}
// console.log(a2)

// 类型收窄
/*typeof 存在的弊端
* 1. typeof 判断数组对象 返回的是object
* 2. typeof 判断普通对象 返回的是object
* 3. typeof 判断日期对象 返回的是object
* 4. typeof 判断正则对象 返回的是object
* 5. typeof 判断null 返回的是object
* */
// const f1 = (a: number | string) => {
//     if (typeof a === 'number') {
//         return a.toFixed(2)
//     } else {
//         return a.trim()
//     }
// }
// f1(1.1245)

// 使用instanceof判断
// const f1 = (a: Array<Date> | Date) => {
//     if (a instanceof Date) {
//         return a.toLocaleString()
//     } else if (a instanceof Array) {
//         return a.map(item => item.toLocaleString())
//     } else {
//         throw new Error('类型错误')
//     }
// }
// console.log(f1([new Date(), new Date()]))

//instanceof 存在的弊端
/*
* 1. instanceof 不可以判断基本类型
* 2. instanceof 不可以判断TS自定义类型
* 3. instanceof 不可以判断 typescript 中特有的类型
* */
//比如如下的例子
// type Person = {
//     name: string
// }
// const f1 = (a: Person | Person[]) => {
//     // if(a instanceof Person){} //这里会报错 因为Person是一个自定义类型 不能使用instanceof判断
//     // if(typeof a === Person){}   //这里也会报错 因为Person是一个自定义类型 不能使用typeof判断
// }

//使用in判断
// type Person = {
//     name: string
// }


// in也只支持部分对象
// const f1 = (a: Person | Person[]) => {
//     if ('name' in a) {
//         return a.name
//     } else {
//         return a.map(item => item.name)
//     }
// }

// // 使用js中判断类型的函数来区分?
// const f1 = (a: string | string[]) => {
//     if(Array.isArray(a)){
//         return a.join('\n').toString()
//     }else if (typeof a === 'string'){
//         return parseFloat(a).toFixed(2)
//     }else {
//         return a
//     }
//
// }

//使用逻辑来收窄类型
// const f1 = (a?: string[]) => {
//     if(a){
//         a //这里的a就是string[]
//     }else{
//         a //这里的a就是undefined
//     }
// }

// const f1 = (x: string | number, y: string | boolean) => {
//     if(x === y){
//         x // string
//         y // string
//     }else{
//         x // string | number
//         y // string | boolean
//     }
// }


//类型谓词 is
// type Rect = { height: number, width: number }
// type Circle = { center: [number, number], radius: number }
//
// function isRect(x: Rect | Circle): x is Rect { //这里的x is Rect就是类型谓词 不可以写boolean
//     return 'height' in x && 'width' in x
// }
//
// const f1 = (a: Rect | Circle) => {
//     if (isRect(a)) {
//         return a.height * a.width
//     } else {
//         return a.radius * a.radius * Math.PI
//     }
// }

/*
is 的优点
1. 支持所有 typescript类型
is 的缺点
麻烦
* */

// 回到上面的问题, 如何使用联合类型? 收窄类型?

// type A = {kind: 'A', a: number}
// type B = {kind: 'B', b: string}
//
// const f1 = (a: A | B) => {
//     if(a.kind === 'A'){
//         return a.a
//     }else{
//         return a.b
//     }
// }

//上面的写法很傻

//可辨别联合

// interface Circle {
//     kind: 'circle',
//     radius: number
// }
//
// interface Square {
//     kind: 'square',
//     sideLength: number
// }
//
// type Shape = Circle | Square
//
// const f1 = (shape: Shape) => {
//     if (shape.kind === 'circle') {
//         return shape.radius * shape.radius * Math.PI
//     } else if (shape.kind === 'square') {
//         return shape.sideLength * shape.sideLength
//     } else {
//         return shape
//     }
// }

//上面的写法就很好
// 让复杂类型的收窄变成 简单类型的收窄
// 一句话总结上面的方案: 同名、可辨别的简单类型的 key

//any 类型 任何类型都可以赋值给any类型 但是any类型不能赋值给其他类型 除非是any类型
// const f1 = (a: any) => {
//     a.toFixed(1)
// }

//unknown类型
// unknown 的优点
// 可以反悔
// const f1 = (a: unknown) => {
//     if (a instanceof Date) {
//         a //这里的a就是Date类型
//     }
// }
export {}