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

export {}