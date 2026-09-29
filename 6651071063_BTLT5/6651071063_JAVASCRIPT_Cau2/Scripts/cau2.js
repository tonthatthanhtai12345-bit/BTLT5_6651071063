var y = parseInt(prompt("Nhập năm:", 2024));
var nhuan = (y % 4 === 0 && y % 100 !== 0) || (y % 400 === 0);
document.getElementById("kq").innerText = "Năm " + y + (nhuan ? " là năm nhuận." : " không phải năm nhuận.");
