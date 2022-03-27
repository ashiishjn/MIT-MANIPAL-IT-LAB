function validate() {
  var usn = document.getElementById("usn").value;
  var check = /[1-4]{1}[A-Z]{2}[0-9]{2}[A-Z]{2}[0-9]{3}/;
  console.log("Checking USN");
  var res = check.test(usn);
  if (!res) {
    alert("Invalid USN");
    return;
  } else {
    sem = document.getElementById("semester").value;
    alert("Your USN is " + usn + "\nSemester: " + sem);
  }
  console.log("Checking Done");
}
