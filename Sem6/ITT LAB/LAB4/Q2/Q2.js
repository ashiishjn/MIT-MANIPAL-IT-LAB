function leftvowel(){
    var txt = document.getElementById("input").value;
    var str = "aeiou";
    var pos = -1;
    for(i=0;i<5;i++)
    {
        a = txt.indexOf(str.charAt(i));
        if(a == -1)
        {
            continue;
        }
        else if(pos == -1)
            pos = a;
        else if(pos > a)
            pos = a;
    }
    document.getElementById("output").textContent = pos.toString();
}

function reverse(){
    var txt = document.getElementById("input").value;
    var reverse = "";
    for(i=0;i<txt.length;i++)
    {
        reverse = txt.charAt(i) + reverse;
    }
    document.getElementById("output").textContent = reverse;
}
