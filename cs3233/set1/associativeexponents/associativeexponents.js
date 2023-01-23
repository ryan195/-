const readline = require('readline')
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
})
rl.once("line", line => {
    var thing = line.split(" ")
    if ((thing[0] == 1) || (thing[2] == 1)) {
        console.log("What an excellent example!")
    } else if ((thing[1] == thing[2]) && (thing[1] == 2)) {
        console.log("What an excellent example!")
    } else {
        console.log("Oh look, a squirrel!")
    }
})
