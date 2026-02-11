class Developer {
  private name: string;

  constructor(name: string) {
    this.name = name;
  }

  getName(): string {
    return this.name;
  }
}

class Team {
  private name: string;
  private devs: Developer[] = [];

  constructor(name: string, devs: Developer[]) {
    this.name = name;
    this.devs = devs;
  }

  printDevs(): void {
    console.log(`Devs in ${this.name} Team: `);
    for (let i of this.devs) {
      console.log(`${i.getName()} \n`);
    }
  }
}
