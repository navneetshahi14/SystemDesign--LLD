class Documents {
  private content: string;

  constructor(content: string) {
    this.content = content;
  }

  getContent(): string {
    return this.content;
  }
}

class Printer {
  printing(docs: Documents): void {
    console.log(`Printing ${docs.getContent()}`);
  }
}

function main1(): void {
  const doc = new Documents("Hello World");
  const printer = new Printer();

  printer.printing(doc);
}


main1();