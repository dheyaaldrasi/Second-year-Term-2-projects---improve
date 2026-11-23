console.log("Hello, World!");

document.write("<h1> Page Title</h1>");

document.querySelector("h1").style.color = "blue";

document.querySelector("h1").style.fontSize = "25px";

// اجبار المتصفح على تنفيذ الاوامر داخل الدالة عند تحميل الصفحة
window.onload = function () {
  document.querySelector("h1").style.color = "red";
}

/*
  1
  2
  3
  4
  5
  6
  7
  8
  9
  multiple lines comment
*/


// window.alert("Hello, from JS file");

document.write("<h4>This is my <span>page</span> title from JS file.</h4>");

// document.createElement() // انشاء عنصر جديد بشكل احترافي وحديث


console.log("log");

console.error("error");

console.warn("warn");

console.info("info");

console.assert(4 > 5, "4 is not greater than 5");

// console.clear();

console.timeStamp("Start");

console.time("Time");

console.table(["Diaa", "Ali", "Mohammed", "Ahmed"]);

console.log("Hello from %cJS %c file", "color: red; font-size: 20px; font-weight: bold", "color: blue; font-size: 15px; font-weight: bold");

let myName = "Diaa";
console.log("Hello "+ myName + " from JS file"); // الطريقة القديمة للطباعة
console.log(`Hello ${myName} from JS file`); // الطريقة الحديثة للطباعة


/*
  Data type Intro
  string
  Number
  Array -> Object

*/

// window.alert("Hello from JS file");
// alert("Hello from JS file");



let user = "Admin";
user = "Diaa";
console.log(user);

// console.log(h1); // undefined

console.log("welcome JS");
console.log('welcome JS');
console.log(`welcome JS`);

console.log("welcome 'JS'");
console.log('welcome \'JS\''); // add '' sign to the string

console.log('welcome "JS"');
console.log("welcome \"JS\""); // add "" sign to the string

console.log('welcome \
         JS'); // new line, but not recommended
console.log('welcome \nJS'); // new line

console.log("Diaa Al-Drasi");
console.log(typeof "Diaa Al-Drasi"); // string
console.log(typeof "500"); // string 
console.log(typeof 500); // number
console.log(typeof 500.5); // number
console.log(typeof true); // boolean
console.log(typeof false); // boolean
console.log(true); // true
console.log(false); // false 
console.log(true + false); //  1 + 0 = 1
console.log(true + true); // 1 + 1 = 2
console.log(false + false); // 0 + 0 = 0
console.log(10 > 5); // true 
console.log(10 < 5); // false
console.log(typeof (10 > 5)); // boolean 
console.log(typeof (10 < 5)); // boolean 
console.log(typeof undefined); // undefined
console.log(undefined); // undefined
console.log(typeof null); // object
console.log(null); // null 
console.log(typeof {name: "Diaa", age: 21, country: "Yemen"}); // object
console.log(typeof [22, 15 , 14]); // object
console.log(typeof function(){}); // function
console.log(typeof NaN); // number
console.log(NaN); // Not a Number
console.log(NaN === NaN); // false
console.log(Number.isNaN(NaN)); // true
console.log(isNaN(NaN)); // true, old way
console.log(0/0); // NaN
console.log(NaN + 5); // NaN
console.log(typeof Infinity); // number
console.log(Infinity);
console.log(2 / 0); // infinity
console.log(typeof -Infinity); // number
console.log(-Infinity);
console.log(-2 / 0); // -infinity
console.log(typeof Number); // Function 
console.log(typeof Symbol()); // symbol, Key to access private properties in objects
console.log(typeof Symbol("Diaa")); // symbol
console.log(typeof Symbol("Diaa") === typeof Symbol("Ali")); // true
console.log(Symbol("Diaa") === Symbol("Ali")); // false
console.log(typeof BigInt(500)); // bigint, numbers that across the limit of Number type
console.log(typeof BigInt("500")); // bigint, Numbers that between the values -2^53 + 1 and 2^53 - 1
console.log(typeof BigInt("500") + 1); // bigint
console.log(typeof BigInt("500") + 1n); // bigint
console.log(typeof BigInt("500") + 1n + 1); // bigint
console.log(10n + 5n); // 15n
console.log(10n - 5n); // 5n
console.log(10n * 5n); // 50n
console.log(10n / 5n); // 2n
console.log(10n % 3n); // 1n
console.log(10n ** 3n); // 1000n, الأسس او الرفع إلى قوة 
console.log(10n > 5n); // true
console.log(10n < 5n); // false
console.log(10n === 10); // false
console.log(10n == 10); // true
console.log(10n !== 10); // true
console.log(10n != 10); // false
console.log(true && false); // false
console.log(true || false); // true
console.log(!true); // false
console.log(!false); // true
console.log(!!true); // true
console.log(!!false); // false
console.log(!!0); // false
console.log(!!1); // true
console.log(!!""); // false
console.log(!!"Diaa"); // true
console.log(!!undefined); // false
console.log(!!null); // false
console.log(!!NaN); // false
console.log(!!Infinity); // true
console.log(!!-Infinity); // true
console.log(!!{}); // true
console.log(!![]); // true
console.log(!!function(){}); // true
console.log("" ?? "Diaa"); // Diaa
console.log(null ?? "Diaa"); // Diaa
console.log(undefined ?? "Diaa"); // Diaa
console.log(false ?? "Diaa"); // false
console.log(0 ?? "Diaa"); // 0
console.log(NaN ?? "Diaa"); // NaN



// read data from the server
const userA = {
  name: "Diaa",
  settings: {
    them: "Dark",
    notifications: 7
  }
};  

const userB = {
  name: "Ali"
};

const userC = null;

const themA = userC?.settings?.them ?? "Light";
const themB = userB?.settings?.them ?? "Light";
const themC = userA?.settings?.them ?? "Light";

console.log(themA); // Light
console.log(themB); // Light  
console.log(themC); // Dark

const countB = userB?.settings?.notifications ?? 5;
console.log(countB);
const countA = userA?.settings?.notifications ?? 5;
console.log(countA);

// end of test reading data from the server


console.log(10e9); // 10000000000
console.log(1_000_000); // 1000000

var $_na$_me$2_1 = "Diaa", // you can start the name of variable with $, or _, but not A Number.
  collage = "IT"; // multi var definition in one line
var age = 21;
var userName = "dheya"; // the camel case is common way in javascript

console.log($_na$_me$2_1);
console.log(age);
console.log(collage);

console.log(option);
option.innerHTML = "Welcome";

/*
  var
    Redeclare (true)
    Access before declare (undefined)
    Variable scope Drama [Added to window] ()
    Block or function Scope ()
  let
    Redeclare (false)
    Access before declare (error)
    Variable scope Drama [Added to window] ()
    Block or function Scope ()
  const
    Redeclare (false)
    Access before declare (error)
    Variable scope Drama [Added to window] ()
    Block or function Scope ()
*/

console.log(a); // undefined
var a = 1;
var a = 2; 
console.log(a); // 2
var aabb = "diaa"; // added to the window object

console.log(b); // error

let b = 1;

// let b = 2; 
// console.log(b); // error



console.log(c); // error
const c = 1;
// const c = 3;
// console.log(c); // error








