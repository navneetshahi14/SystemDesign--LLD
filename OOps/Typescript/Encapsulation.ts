class Product {
  private name: string;
  private price: number;

  constructor(name: string, price: number) {
    this.name = name;
    this.price = price;
  }

  getName(): void {
    console.log(this.name);
  }
  getPrice(): void {
    console.log(this.price);
  }
}

class Products {
  private _name: string;
  private _price: number;

  constructor(name: string, price: number) {
    this._name = name;
    this._price = price;
  }

  get name(): string {
    return this._name;
  }

  get price(): number {
    return this._price;
  }

  set price(value: number) {
    if (value <= 0) {
      throw new Error(`Price should more than zero`);
    }
    this._price = value;
  }
}
