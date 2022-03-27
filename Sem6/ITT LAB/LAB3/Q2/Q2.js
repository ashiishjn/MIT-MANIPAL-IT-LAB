function piglatin(text) {
  var text = document.getElementById("Q2").value;
  var a = text.split(" ");
  var s = "";
  var n = a.length;
  var i;
  var txt;
  document.getElementById("Q2").textContent = "";
  for (i = 0; i < n; i++) {
    txt = a[i];
    var s = "";
    s = txt.substring(1, txt.length);
    s += txt.charAt(0);
    s += "ay";
    var temp = document.getElementById("display").innerHTML;
    s = temp + " " + s;
    document.getElementById("display").textContent = s;
  }
}
