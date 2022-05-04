var oldValue;
function bringToTop(element) {
  oldValue = element.style.zIndex;
  element.style.zIndex = 3;
}

function resetPosition(element) {
  element.style.zIndex = oldValue;
}

// var boxes = document.getElementsByClassName("box");
// Array.from(boxes).forEach((element, index) => {
//   element.onmouseover = () => bringToTop(element);
//   element.onmouseout = () => resetPosition(element);
// });
