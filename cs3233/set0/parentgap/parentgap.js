const readline = require('readline')
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
})
rl.once("line", line => {
    for (let i = 1; i <= 3; i++) {
        var d = new Date(line + "-05-0" + i)
        if (d.getDay() == 0) {
            console.log("6 weeks")
            return 0
        }
    }
    console.log("5 weeks")
    return 0;
})