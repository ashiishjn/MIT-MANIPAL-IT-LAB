function fib(n)
{
    var a=[0,1];
    var str ="0, 1, ";
    for(i=2;i<n;i++)
    {
        a.push(a[i-1]+a[i-2]);
        str+=a[i].toString()+", ";
    }
    document.getElementById("display").textContent = str;
}

function sq(n)
{
    var a=[];
    str = "";
    for(i=1;i<=n;i++)
    {
        var sqares = i*i;
        str+= i.toString()+"    "+sqares.toString()+"\n";
    }
    alert (str);  
}

function table(){
    var value = prompt("Enter n", "10");
    var array = sq(Number(value));
}


function fibonacci(){
    var value = prompt("Enter n", "10");
    var array = fib(Number(value));
    
}
