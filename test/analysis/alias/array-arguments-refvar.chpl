config const n = 10;

proc main() {
  var A: [1..10] int;
  var B: [1..10] int = 1;
  ref R = B;
  test(A, R);
  writeln(A);
}

proc test(a, b) {
  for i in 1..n {
    a[1] += b[1];
  }
}
