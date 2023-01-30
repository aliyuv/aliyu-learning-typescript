// interface IConfig {
//     a: string | number
// }
// // const current = {} satisfies IConfig //error
// // current.a = 1
// const currentWith = {a: 1} satisfies IConfig
// console.log(currentWith.a)
// console.log(currentWith.a.toFixed())
interface User{
    readonly id: string | number
    name: string
    age: number
}

type Dog = {
    name: string
}
// interface UserWithDog extends User {
//     pet: Dog
// }

interface UserWithPet<T> extends  User {
    pet: T
}

const u1: UserWithPet<Dog> = {
    id: 1,
    name: 'John',
    age: 20,
    pet: {name: 'Rex'}
}
console.log(u1.pet?.name)
export {}