class Car {
  private brand: string;
  private model: string;
  private speed: number;

  constructor(brand: string, model: string) {
    this.brand = brand;
    this.model = model;
    this.speed = 0;
  }

  accelerate(increment: number): void {
    this.speed += increment;
  }

  displayStatus(): void {
    console.log(`${this.brand} is running at ${this.speed} km/hr.`);
  }
}

let myCar = new Car("BMW", "M4");
myCar.accelerate(10);
myCar.displayStatus();
