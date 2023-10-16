# Resources

- [Flowbite: Tailwind CSS Copy-paste Library](https://flowbite.com/docs/getting-started/react/)

## Scripts

```bash
npm create vite@latest repo-name -- --template react;
cd repo-name;
npm install;
npm install react-router-dom react-router;
npm install -D tailwindcss postcss autoprefixer;
```

## Tailwind Config

```js
/** @type {import('tailwindcss').Config} */
export default {
  content: ['./index.html', './src/**/*.{js,ts,jsx,tsx}'],
  theme: {
    extend: {
      colors: {
        primary: '#6300ef',
        'primary-variant': '#3701b2',
        secondary: '#02dbc6',
        'secondary-variant': '#018786',
        error: '#b10021',
        background: '#fefffe',
        'on-background': '#010001',
      },
    },
  },
  plugins: [],
};
```

## ESLint Config

```js
module.exports = {
  root: true,
  env: { browser: true, es2020: true },
  extends: [
    'eslint:recommended',
    'plugin:react/recommended',
    'plugin:react/jsx-runtime',
    'plugin:react-hooks/recommended',
  ],
  ignorePatterns: ['dist', '.eslintrc.cjs'],
  parserOptions: { ecmaVersion: 'latest', sourceType: 'module' },
  settings: { react: { version: '18.2' } },
  plugins: ['react-refresh'],
  rules: {
    'react-refresh/only-export-components': [
      'warn',
      { allowConstantExport: true },
    ],
    'react/prop-types': 'off',
  },
};
```
