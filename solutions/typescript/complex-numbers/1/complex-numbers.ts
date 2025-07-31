export class ComplexNumber {
  re: number
  im: number

  constructor(real: number, imaginary: number) {
    this.re = real
    this.im = imaginary
  }

  public get real(): number {
    return this.re
  }

  public get imag(): number {
    return this.im
  }

  public add(other: ComplexNumber): ComplexNumber {
    return new ComplexNumber(this.re + other.re, this.im + other.im) 
  }

  public sub(other: ComplexNumber): ComplexNumber {
    return new ComplexNumber(this.re - other.re, this.im - other.im) 
  }

  public div(other: ComplexNumber): ComplexNumber {
    const denominator = other.re * other.re + other.im * other.im 
    return new ComplexNumber((this.re * other.re + this.im * other.im) / denominator, (this.im * other.re - this.re * other.im) / denominator)
  }

  public mul(other: ComplexNumber): ComplexNumber {
    return new ComplexNumber(this.re * other.re - this.im * other.im, this.im * other.re + this.re * other.im);
  }

  public get abs(): number {
    return Math.sqrt(this.re * this.re + this.im * this.im)
  }

  public get conj(): ComplexNumber {
    return new ComplexNumber(this.re, this.im !== 0 ? -this.im : 0)
  }

  public get exp(): ComplexNumber {
   return new ComplexNumber(Math.pow(Math.E, this.re), 0).mul(new ComplexNumber(Math.cos(this.im), Math.sin(this.im))) 
  }
}
